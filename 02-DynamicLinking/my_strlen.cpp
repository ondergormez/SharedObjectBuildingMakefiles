int my_strlen(const char *string)
{
	const char *character;
	for (character = string; *character; ++character);

	return character - string;
}