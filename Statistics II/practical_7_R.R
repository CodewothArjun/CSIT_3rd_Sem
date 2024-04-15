markstesti=c(12, 7,	15,	11,	17,	19,	5,	13,	17,	6,	9,	18,	14,	10,	8)
markstestii=c(14,	5,	17,	13,	12, 18,	9,	10,	18,	12,	3,	14,	16,	16,	8)
t.test(markstesti,markstestii,aternative="less",conf.level = 0.99,paired = TRUE)
#default ma independent garcha so use alternative for two tail