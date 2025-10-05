-- Last updated: 10/5/2025, 8:54:17 AM
# Write your MySQL query statement below
select tweet_id from Tweets
where char_length(content)>15