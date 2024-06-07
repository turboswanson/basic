-- THE FIRST SESSION

BEGIN;

UPDATE pizzeria
SET name = 'pizzeria1'
WHERE id = 1;

UPDATE pizzeria
SET name = 'pizzeria2'
WHERE id = 2;

COMMIT;

-- THE SECOND SESSION

BEGIN;

UPDATE pizzeria
SET name = 'pizzeria_2'
WHERE id = 2;

UPDATE pizzeria
SET name = 'pizzeria_1'
WHERE id = 1;

COMMIT;