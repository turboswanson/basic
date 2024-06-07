-- THE FIRST SESSION

BEGIN TRANSACTION ISOLATION LEVEL REPEATABLE READ;

SELECT *
FROM pizzeria
WHERE name = 'Pizza Hut';

UPDATE pizzeria
SET rating = 4.0
WHERE name = 'Pizza Hut';

COMMIT;

SELECT *
FROM pizzeria
WHERE name = 'Pizza Hut';

--THE SECOND SESSION

BEGIN TRANSACTION ISOLATION LEVEL REPEATABLE READ;

SELECT *
FROM pizzeria
WHERE name = 'Pizza Hut';

UPDATE pizzeria
SET rating = 3.6
WHERE name = 'Pizza Hut';

COMMIT;

SELECT *
FROM pizzeria
WHERE name = 'Pizza Hut';