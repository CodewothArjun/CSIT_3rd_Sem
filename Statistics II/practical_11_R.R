Gender=c("M", "F", "M", "M",  "F",  "M",  "F",  "M",  "F",  "F",  "F",  "M",  "F",  "F",  "M",  "F",  "M",  "F",  "F",  "M")
Eyecolor=c("Bk",
            "Bk",
            "Br",
            "Bk",
            "Bl",
            "Br",
            "Bk",
            "Bk",
            "Bk",
            "Br",
            "Bk",
            "Bk",
            "Bl",
            "Br",
            "Bk",
            "Bk",
            "Br",
            "Bk",
            "Bk",
            "Br")
table(Gender,Eyecolor)
chisq.test(table(Gender,Eyecolor))

#they are independent
