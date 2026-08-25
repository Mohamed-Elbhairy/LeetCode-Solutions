SELECT r.contest_id ,
 ROUND((count(r.user_id)/(SELECT count(*)FROM users))*100,2) as percentage 
FROM Register r INNER JOIN users u
    ON r.user_id = u.user_id
GROUP BY r.contest_id
ORDER BY percentage DESC , contest_id ASC
