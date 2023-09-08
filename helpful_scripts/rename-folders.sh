#!/bin/bash

new_folder_name_prefix="Leetcode_"

for another_folder in [0-9]*; do
    echo "Current Folder : '${another_folder}'"

    new_folder_name="${new_folder_name_prefix}${another_folder}"

    mv ${another_folder} ${new_folder_name}
    echo "Folder New Name: '${new_folder_name}'"
    echo ""
done


# Remove temporary files upon execution
rm *~
