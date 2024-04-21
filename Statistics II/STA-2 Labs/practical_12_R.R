#if it is dependent in parametric t test, in non parametric wilcox test
TestImarks=c(12,	7,	15,	11,	17,	19,	5,	13,	17,	6,	9,	18,	14,	10,	8)
TestIImarks=c(14,	5,	17,	13,	12,	18,	9,	10,	18,	12,	3, 14,	16,	16,	8)
wilcox.test(TestImarks,TestIImarks,paired = TRUE, alternative = "less")
