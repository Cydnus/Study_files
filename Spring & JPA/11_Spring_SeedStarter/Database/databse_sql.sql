insert into seed_starter(covered, date_planted, type) 
values(	0,'2002-04-05 10:10:10', 'PLASTIC');

insert into seed_starter(covered, date_planted, type) 
values(	0,'2001-04-05 10:10:10', 'WOOD');
insert into seed_starter(covered, date_planted, type) 
values(	1,'2003-04-05 10:10:10', 'ALL');

insert into feature(name, seed_starter_id)
values ('SUBSTRATE', 1);
insert into feature(name, seed_starter_id)
values ('PH_CORRECTOR', 1);
insert into feature(name, seed_starter_id)
values ('FERTILIZER', 2);
insert into feature(name, seed_starter_id)
values ('PH_CORRECTOR', 3);

select * 
from seed_starter as s
natural join feature as f;


INSERT INTO detail(ROW_NUM,SEED_PER_CELL, VARIETY, SEED_STARTER_ID) VALUES(1,10,'Thymus vularis',1);
INSERT INTO detail(ROW_NUM,SEED_PER_CELL, VARIETY, SEED_STARTER_ID) VALUES(2,15,'Thymus pseudolaginosus',1);
INSERT INTO detail(ROW_NUM,SEED_PER_CELL, VARIETY, SEED_STARTER_ID) VALUES(3,20,'x citriodorus',1);
INSERT INTO detail(ROW_NUM,SEED_PER_CELL, VARIETY, SEED_STARTER_ID) VALUES(1,5,'Thymus herba-barona',2);
INSERT INTO detail(ROW_NUM,SEED_PER_CELL, VARIETY, SEED_STARTER_ID) VALUES(2,5,'Thymus serpyllum',2);
INSERT INTO detail(ROW_NUM,SEED_PER_CELL, VARIETY, SEED_STARTER_ID) VALUES(1,20,'New Variety',3);


select * 
from seed_starter as s
natural join detail as d;

#전체 정보 확인
select * 
from seed_starter as s
natural join detail as d
natural join feature as f;
