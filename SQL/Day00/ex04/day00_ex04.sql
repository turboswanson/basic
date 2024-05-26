SELECT CONCAT(p.name ,' (age:',p.age,',','gender:''',p.gender,
				''',address:''', p.address, ''')')
		AS personal_info
FROM person AS p
ORDER BY
	personal_info ASC