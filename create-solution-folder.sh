#!/bin/bash


# Output formatters
bold_text=$(tput bold)
normal_text=$(tput sgr0)

# Script Variables
proper_usage_string="${bold_text}Proper usage:${normal_text} 'create-solution-folder -lang cpp/python/java/swift -platform leetcode/hackerrank -problemNumber number -problemTitle(this is optional) title'"

# Usage

# create-solution-folder -lang cpp/python/java/swift -platform leetcode/hackerrank -problemNumber ### -problemTitle(this is optional) title 

# Check number of command line arguments

if [ "$#" -lt 3 ]; then
    echo ${proper_usage_string}
fi

# Extra Extra:
# 1. Create a Readme file in every solution folder
# 1a. This Readme file can contain:
# 1a1. Link to Problem
# 1a2. Solution approaches to different types of solutions, brute-force, better, optimal


# Arguments needed are:
# 1. Leetcode(-lc) or Hackerrank(-hr), other(-ran)
# 2. Number of problem
# 3. Title of problem(would be great if I could retrieve it myself
# 4. Language in which I am planning to code said problem("flags or simple text. -cpp / 'cpp'")
# 5. Extras:
# 5a. Make code clean using software engineering principles
# 5b. Check for all conditions of input

# Script is supposed to:
# 1. Create a solution folder, in the appropriate repository, based on the given command line arguments
# 2. Create a git branch if one doesnt exist already, based on input received
# 2a. Checkout that branch depending on what branch I am currently in
