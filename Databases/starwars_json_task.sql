CREATE TABLE content (
    id SERIAL PRIMARY KEY,
    json JSONB
);

SELECT json->>'name' AS name, id FROM content;

SELECT json->>'name' AS name FROM content WHERE json->>'eye_color' = 'blue';

SELECT json->>'hair_color' AS hair_color, array_agg(json->>'name') AS names FROM content GROUP BY json->>'hair_color';

SELECT json->>'name', json->>'height' FROM content ORDER BY (json->>'height')::int DESC LIMIT 1;

SELECT json->>'name', json->>'height' FROM content WHERE json->>'height' ~ '^[0-9]+$' ORDER BY (json->>'height')::int ASC LIMIT 1;

SELECT json->>'name' FROM content WHERE 'https://swapi.dev/api/starships/12/' = ANY (SELECT jsonb_array_elements_text(json->'starships'));

SELECT json->>'name' FROM content WHERE json->'starships' = '[]'::jsonb OR json->'starships' IS NULL;

SELECT json->>'name', json->>'mass' FROM content WHERE json->>'mass' ~ '^[0-9]+$' ORDER BY (json->>'mass')::int;

SELECT COUNT(*) FROM content WHERE 'https://swapi.dev/api/films/1/' = ANY (SELECT jsonb_array_elements_text(json->'films'));

WITH luke AS (
    SELECT (json->>'height')::int AS height
    FROM content
    WHERE json->>'name' = 'Luke Skywalker'
)
SELECT json->>'name', json->>'height'
FROM content, luke
WHERE (json->>'height')::int > luke.height;

SELECT COUNT(*) FROM content WHERE json ? 'was present in animated series';

UPDATE content SET json = jsonb_set(json, '{was present in animated series}', '"yes"') WHERE id IN (1,2,3);

UPDATE content SET json = json - 'was present in animated series';

SELECT jsonb_pretty(json) FROM content LIMIT 3;

SELECT DISTINCT jsonb_object_keys(json) AS key FROM content;

SELECT pg_typeof(json->>'height') AS height_type FROM content LIMIT 1;