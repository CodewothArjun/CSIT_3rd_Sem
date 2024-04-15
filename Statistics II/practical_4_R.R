CSITresult=c("P", "P",	"F",	"P"	,"P",	"P",	"P",	"F", "P",
             "P",	"P",	"F",	"P",	"F",	"P",	"P",	"P",	"P",
             "F",	"P",	"P",	"P",	"F",	"F",	"P",	"P",	"P",
             "P",	"F",	"P",	"P",	"P",	"F",	"P"	,"P",	"P")
BITresult=c("P",	"F",	"P",	"P",	"P", "P",	"F",	"F",
            "F",	"F",	"P",	"P",	"P",	"P",	"P",	"P",
            "P",	"P",	"F",	"F",	"P",	"P",	"F",	"P",
            "P",	"F",	"F",	"P",	"P",	"F",	"P",	"P")
table(BITresult)
table(CSITresult)
prop.test(c(21,27),c(32,36),)
