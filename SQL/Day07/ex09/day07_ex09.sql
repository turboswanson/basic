SELECT p.address,ROUND(MAX(p.age::numeric)-(MIN(p.age::numeric)/MAX(p.age::numeric)),2) AS formula,
       ROUND(AVG(p.age),2),
       (MAX(p.age)-(MIN(p.age)/MAX(p.age))) > ROUND(AVG(p.age),2) AS comparison
FROM person AS p
GROUP BY p.address
ORDER BY 1;
