Laptop=c("D","D","D","D","A","A","A","A","A","A","A","H","H","H","H","H","L","L","L","L","L","L")
OperatingTime=c(5.3,	4.8,	6.1,	3.5,5.2,	5.8,	3.9,	4.6,	4.9,	5.1,	5.6,4.5,	5.2,	3.8,	4.8,	5.3,4.7,	6.2,	5.7,	5.5,	3.9,	4.8)
kruskal.test(OperatingTime~Laptop)
