#!/bin/bash

teal="\033[0;36m"
NC="\033[m"
destination_folder="Coding-Problems/"

echo "Rearranging folders to create two main folders:"
echo -e "1. ${teal}Coding-Problems${NC}"
echo -e "2. ${teal}helpful_scripts${NC}"
echo ""


for leetcode_folder in Leetcode*; do
    if [ -d "${leetcode_folder}" ]; then
	mv ${leetcode_folder} "${destination_folder}Leetcode/${leetcode_folder}"
	echo -e "${teal}${leetcode_folder}${NC} is the leetcode folder"
    fi
done

for template_folder in *template; do
    if [ -d "${template_folder}" ]; then
	mv ${template_folder} "${destination_folder}templates/${template_folder}"
	echo -e "${teal}${template_folder}${NC} is a template folder"
    fi
done

# Clear the temporary files created
echo ""
