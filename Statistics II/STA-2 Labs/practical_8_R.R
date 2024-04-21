install.packages("randtests")
library(randtests)
outcomes=c("H", "H", "T", "H", "T", "H", "H", "T", "T", "H", "T", "H", "H", "T", "T", "H", "H", "H", "T" , "H", "T", "H", "H",  "T", "T", "H", "T", "T", "T", "H")
randtests.aux(outcomes)

install.packages("snpar")
library("snpar")
runs.test(outcomes)

outcomes=c("H", "H", "T", "H", "T", "H", "H", "T", "T", "H", "T", "H", "H", "T", "T", "H", "H", "H", "T" , "H", "T", "H", "H",  "T", "T", "H", "T", "T", "T", "H")
table(outcomes)
binom.test(16,30,0.5)


# Coin toss outcomes
outcomes = c("H", "H", "T", "H", "T", "H", "H", "T", "T", "H", "T", "H", "H", "T", "T", "H", "H", "H", "T", "H", "T", "H", "H", "T", "T", "H", "T", "T", "T", "H")

# Convert "H" to 1 and "T" to 0
numeric_outcomes = ifelse(outcomes == "H", 1, 0)

# Perform runs test
runs_test_result = runs.test(numeric_outcomes)

# Print result
print(runs_test_result)

# Load the DescTools package (if not already loaded)
install.packages(DescTools)

# Sample data
data <- rnorm(100)  # Generate 100 random normal values

# Perform runs test
runs_test_result <- RunsTest(data)

# Print the results
summary(runs_test_result)
