int my_strcmp(const char *leftString, const char *rightString)
{
    for (; *leftString == *rightString; ++leftString, ++rightString) {
        if (*leftString == '\0') {
            return 0;
        }
    }

    return *leftString - *rightString;
}