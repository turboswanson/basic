WITH period AS(
    SELECT
    generate_series('2022-01-01','2022-01-10',interval '1 day') 
    AS period
) 

SELECT period::date AS missing_date
FROM period
LEFT JOIN person_visits AS pv
ON pv.visit_date = period AND (pv.person_id = 1 OR pv.person_id = 2)
WHERE pv.visit_date IS NULL
ORDER BY 1;
