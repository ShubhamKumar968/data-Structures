-- Method-01: Using Dense_rank {10,20,30,30,30,40 => dense rank=1,2,3,3,3,4:  rank=> 1,2,3,3,3,6}

select max(t.salary) as SecondHighestSalary

from (
    select
        salary,
        dense_rank() over (order by salary desc) as rnk
        from Employee
    ) t
    
where t.rnk = 2;

--Method-02: maximum salary ko hata kar ke jo remaining hai uska maximum return kar do.
select max(salary) as SecondHighestSalary from Employee
where salary not in( select max(salary) from Employee );

