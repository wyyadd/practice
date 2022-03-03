# Write your MySQL query statement below
# SELECT DISTINCT A.num AS ConsecutiveNums FROM Logs A, Logs B, Logs C
# WHERE A.num = B.num AND B.num = C.num AND B.id - 1 = A.id AND C.id - 1 = B.id;
select distinct Num as ConsecutiveNums
from Logs
where (Id + 1, Num) in (select * from Logs) and (Id + 2, Num) in (select * from Logs);
