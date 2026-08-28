// Problem Link: https://leetcode.com/problems/movie-rating/

(
    SELECT u.name AS results
    FROM Users u
    ORDER BY (
        SELECT SUM(CASE WHEN u.user_id = MV.user_id THEN 1 ELSE 0 END) 
        FROM MovieRating MV
    ) DESC, u.name ASC
    LIMIT 1
)
UNION ALL
(
    SELECT M.title AS results
    FROM Movies M
    ORDER BY (
        SELECT AVG(CASE WHEN M.movie_id = MV.movie_id THEN MV.rating ELSE NULL END)
        FROM MovieRating MV
        WHERE MV.created_at BETWEEN '2020-02-01' AND '2020-02-29'
    ) DESC, M.title ASC
    LIMIT 1
);
