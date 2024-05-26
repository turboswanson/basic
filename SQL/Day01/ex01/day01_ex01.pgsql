SELECT object_name
FROM
    (SELECT pizza_name as object_name,'menu' as label
    FROM menu
    UNION ALL
    SELECT name,'person' as label
    FROM person
    ORDER BY LABEL DESC,1) AS t;