# Write your MySQL query statement below
#select(select distinct salary  from Employee order by salary desc limit 1 offset 1) as SecondHighestSalary
select max(salary)  as SecondHighestSalary from Employee e where e.salary <>(select max(salary) from   Employee)