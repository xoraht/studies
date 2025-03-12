def czy_suma(L, K):
    if K > sum(L) or K <= 0: return
    elif K == sum(L): return True
    else:
        mozliwe_sumy = set([0])
        for liczba in L:
            nowe_sumy = set()
            for aktualna_suma in mozliwe_sumy:
                nowa_suma = aktualna_suma + liczba
                if nowa_suma == K:
                    return True
                nowe_sumy.add(nowa_suma)
            mozliwe_sumy.update(nowe_sumy)
        return K in mozliwe_sumy

L = [2, 3, 5, 8, 13]
K = 5

print(f"Liczbę {K} {'' if czy_suma(L, K) else 'nie '}można przedstawić jako sumę liczb z listy {L}.")