SELECT name
FROM stars JOIN people ON stars.person_id = people.id
where MOVIE_ID in
(SELECT movie_id
FROM stars JOIN people ON stars.person_id = people.id
WHERE birth = 1958 and name = "Kevin Bacon")
AND name != "Kevin Bacon"