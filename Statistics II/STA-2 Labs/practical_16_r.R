rent=c(16,	20,	25,	22,	20,	25)
noofrooms=c(4,	6,	3,	4,	5,	3)
distance=c(8,	10,	4,	6,	2,	1)
summary(lm(rent~noofrooms+distance))
prent=27.3954-0.9414*2-0.4141*8
prent
residuals(lm(rent~noofrooms+distance))
