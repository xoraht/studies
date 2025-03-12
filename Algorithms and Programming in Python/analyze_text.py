def analyze_text(text):
    word_list = text.split()
    
    all_words = ''.join(word_list).replace('.', '').replace(',', '')
    average_word_length = round(len(all_words) / len(text.split()), 2)
    
    letter_list = list(text.replace('.', '').replace(',', '').replace(' ', '').lower())
    letter_dictionary = {}
    for letter in letter_list:
        letter_dictionary[letter] = letter_list.count(letter)
    
    word_list = text.replace('.', '').replace(',', '').lower().split(" ")
    word_dictionary = {}
    for word in word_list:
        word_dictionary[word] = word_list.count(word)
    word_dictionary = sorted(word_dictionary.items(), key = lambda x: x[1], reverse=True)
    most_common_words = []
    #for i in range(len(word_dictionary)):
    #    most_common_words.append(word_dictionary[i][0])
    #    if(word_dictionary[i][1] != word_dictionary[i + 1][1]): break
    for i in range(3):
        most_common_words.append(word_dictionary[i][0])
    return {
        'liczba_slow': len(word_list),
        'dlugosc_srednia_slowa': average_word_length,
        'liczba_wystapien_liter': letter_dictionary,
        'najczestsze_slowa': most_common_words
    }

text = "To jest przykładowy tekst. Zawiera kilka zdań, kilka słów, i kilka liter. Tekst ten jest do analizy."
print(analyze_text(text))


