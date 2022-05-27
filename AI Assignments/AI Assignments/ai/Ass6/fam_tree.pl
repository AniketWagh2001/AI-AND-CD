female(ada).
female(polly).
female(linda).
female(grace).
female(lizzie).
female(esme).
female(ruby).

male(charles).
male(billy).
male(karl).
male(thomas).
male(john).
male(arthur_jr).
male(arthur_sr).
male(finn).
male(michael).
male(freddie).

parent(arthur_sr,arthur_jr).
parent(arthur_sr,thomas).
parent(arthur_sr,john).
parent(arthur_sr,finn).
parent(arthur_sr,ada).


parent(arthur_jr,billy).
parent(linda,billy).

parent(thomas,charles).
parent(grace,charles).

parent(thomas,ruby).
parent(lizzie,ruby).

parent(freddie,karl).
parent(ada,karl).

parent(polly,michael).

mother(X,Y) :- parent(X,Y),female(X).
father(X,Y) :- parent(X,Y),male(X).
haschild(X) :- parent(X,_).
sister(X,Y) :- parent(Z,X),parent(Z,Y),female(X),X\==Y.
brother(X,Y) :- parent(Z,X),parent(Z,Y),male(X),X\==Y.
grandfather(X,Y) :- male(X), parent(X,Z),parent(Z,Y).
grandmother(X,Y) :- female(X), parent(X,Z),parent(Z,Y).
aunt(X,Y) :- female(X),parent(Z,Y),sister(Z,X).
uncle(X,Y) :- male(X),parent(Z,Y),brother(Z,X).
