result=c("P",	"P",	"P",	"F",	"P",	"F",	"P",	"P",
         "F",	"F",	"P",	"P",	"P",	"P",	"F",	"P",
         "P",	"P",  "F",	"P",	"P",	"P",	"F",	"P",
         "P",	"F",	"P",	"P",	"P",	"F",	"P",	"P")
table(result)
prop.test(23,32,0.8)
#sample_size=Zalpha2pq/d2
sample_size=1.96^2*0.71875*(1-0.71875)/(0.05)^2
sample_size
