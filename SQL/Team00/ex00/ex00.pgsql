-- CREATE TABLE IF NOT EXISTS nodes
-- (point1 varchar,
-- point2 varchar,
-- cost numeric);

-- INSERT INTO nodes(point1,point2,cost)
-- VALUES  ('a','b',10),
--         ('b','a',10),
--         ('b','c',35),
--         ('c','b',35),
--         ('c','a',15),
--         ('a','c',15),
--         ('a','d',20),
--         ('d','a',20),
--         ('b','d',25),
--         ('d','b',25),
--         ('c','d',30),
--         ('d','c',30);




WITH RECURSIVE tmp AS(
    SELECT *
    FROM nodes
    WHERE point1 = 'a' 

    UNION

    SELECT *
    FROM nodes
    WHERE point1 != 'a' AND point2 != 'a'

)

SELECT *
FROM tmp
ORDER BY 1;