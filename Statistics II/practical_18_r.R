laptop=c("A","H","D","H","D","L","L","A","H","L","L","A","H","D","L","D","A","D","A","L","A","H","D","H")
OperatingTime=c(
                5.2,
                3.8,
                4.6,
                5.2,
                3.6,
                4.4,
                5.6,
                3.9,
                4.6,
                6.2,
                4.8,
                3.5,
                
                4.4,
                3.6,
                5.2,
                4.8,
                4.2,
                5.4
                ,
                6.1,
                4.7,
                3.2,
                5.3,
                4.8,
                3.9
)
summary(aov(OperatingTime~laptop))
#TukeyHSD(aov(OperatingTime~laptop))#only for h0 rejection 
         
         