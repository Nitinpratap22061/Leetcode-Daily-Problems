-- Last updated: 10/5/2025, 8:56:08 AM
# Write your MySQL query statement below
select distinct author_id as id from Views
where author_id=viewer_id
order by id