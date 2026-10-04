# the-company

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Amber's conglomerate corporation just acquired some new companies. Each of the companies follows this hierarchy: <img src="https://s3.amazonaws.com/hr-challenge-images/19505/1458531031-249df3ae87-ScreenShot2016-03-21at8.59.56AM.png"/>

Given the table schemas below, write a query to print the _company\_code_, _founder_ name, total number of _lead_ managers, total number of _senior_ managers, total number of _managers_, and total number of _employees_. Order your output by ascending _company\_code_.

**Note:**

- The tables may contain duplicate records.
- The _company\_code_ is string, so the sorting should not be **numeric**. For example, if the _company\_codes_ are _C\_1_, _C\_2_, and _C\_10_, then the ascending _company\_codes_ will be _C\_1_, _C\_10_, and _C\_2_.

----

**Input Format**

The following tables contain company data:

- _Company:_ The _company\_code_ is the code of the company and _founder_ is the founder of the company. <img src="https://s3.amazonaws.com/hr-challenge-images/19505/1458531125-deb0a57ae1-ScreenShot2016-03-21at8.50.04AM.png"/>

- _Lead\_Manager:_ The _lead\_manager\_code_ is the code of the lead manager, and the _company\_code_ is the code of the working company. <img src="https://s3.amazonaws.com/hr-challenge-images/19505/1458534960-2c6d764e3c-ScreenShot2016-03-21at8.50.12AM.png"/>

- _Senior\_Manager:_ The _senior\_manager\_code_ is the code of the senior manager, the _lead\_manager\_code_ is the code of its lead manager, and the _company\_code_ is the code of the working company. <img src="https://s3.amazonaws.com/hr-challenge-images/19505/1458534973-6548194998-ScreenShot2016-03-21at8.50.21AM.png"/>

- _Manager:_ The _manager\_code_ is the code of the manager, the _senior\_manager\_code_ is the code of its senior manager, the _lead\_manager\_code_ is the code of its lead manager, and the _company\_code_ is the code of the working company. <img src="https://s3.amazonaws.com/hr-challenge-images/19505/1458534988-7fc0af46ce-ScreenShot2016-03-21at8.50.29AM.png"/>

- _Employee:_ The _employee\_code_ is the code of the employee, the _manager\_code_ is the code of its manager, the _senior\_manager\_code_ is the code of its senior manager, the _lead\_manager\_code_ is the code of its lead manager, and the _company\_code_ is the code of the working company. <img src="https://s3.amazonaws.com/hr-challenge-images/19505/1458535002-d47f63cbb4-ScreenShot2016-03-21at8.50.41AM.png"/>

----

**Constraints**

 

**Output Format**

## Solution

**Language:** SQL  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-04T09:25:03.555Z  

```sql
/*
Enter your query here.
*/
select
    c.company_code,
    c.founder,
    count(distinct lm.lead_manager_code) as lean_manager_count,
    count(distinct sm.senior_manager_code) as senior_manager_count,
    count(distinct m.manager_code) as manager_count,
    count(distinct e.employee_code) as employee_count
from Company c 
left join Lead_Manager lm
    on c.company_code = lm.company_code
left join Senior_manager sm
    on c.company_code = sm.company_code
left join Manager m 
    on c.company_code= m.company_code
left join Employee e 
    on c.company_code = e.company_code
group by 
    c.company_code,
    c.founder
order by c.company_code;

```

---

[View on HackerRank](https://www.hackerrank.com/challenges/the-company/problem)