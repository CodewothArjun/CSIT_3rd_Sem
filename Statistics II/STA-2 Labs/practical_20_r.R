laptop=c("A", "H", "D", "L", "L", "A", "H", "D", "H", "D", "L", "A", "D", "L", "A", "H")
row=c("1","1","1","1","2","2","2","2","3","3","3","3","4","4","4","4")
column=c("1","2","3","4","1","2","3","4","1","2","3","4","1","2","3","4")
OperatingTime=c(4.2, 4.8, 4.2, 6.2, 4.6, 5.9, 4.8, 5.2, 5.4, 5.6, 5.6, 4.8, 4.1, 5.7, 4.2, 4.3)
summary(aov(OperatingTime~laptop+row+column))
