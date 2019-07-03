#include <vector>
#include <algorithm>
using std::vector;
vector<std::string> split(const std::string& str, const std::string& delim) {
    vector<std::string> tokens;
    size_t prev = 0, pos = 0;
    do {
        pos = str.find(delim, prev);

        if (pos == std::string::npos) pos = str.length();

        std::string token = str.substr(prev, pos-prev);

        if (!token.empty()) tokens.push_back(token);

        prev = pos + delim.length();
    } while (pos < str.length() && prev < str.length());

    return tokens;
}
size_t strpos(const std::string &haystack, const std::string &needle) {
    int sleng = haystack.length();
    int nleng = needle.length();

    if (sleng==0 || nleng==0)
        return std::string::npos;

    for(int i=0, j=0; i<sleng; j=0, i++ ) {
        while (i+j<sleng && j<nleng && haystack[i+j]==needle[j])
            j++;

        if (j==nleng)
            return i;
    }

    return std::string::npos;
}
