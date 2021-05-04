class WordCounter
{
public:
	int value;
	WordCounter() : value(0) {}

	void operator++ (int) { value++; }
};
