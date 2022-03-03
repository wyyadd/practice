select
if(id < (select count(*) from seat), if(id & 1 = 0, id-1, id+1), if(id & 1 = 0, id-1, id)) as id, student
from seat
order by id asc;
