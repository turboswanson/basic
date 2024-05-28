
select count(*)=9 as check
       from person_order
       where order_date='2022-02-25' and menu_id = (select id from menu where pizza_name = 'greek pizza')