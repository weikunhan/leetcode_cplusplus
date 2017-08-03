//==============================================================================
// 194. Transpose File
// C++
// Tag:
//==============================================================================
// Summary:
// https://leetcode.com/problems/transpose-file/description/

# Read from the file file.txt and print its transposed content to stdout.

awk '{
    for (i = 1; i <= NF; i++) {
        if(NR == 1) {
            line[i] = $i;
        } else {
            line[i] = line[i] " " $i;
        }
    }
}
END {
    for (i = 1; line[i] != ""; i++) {
        print line[i];
    }
}' file.txt
