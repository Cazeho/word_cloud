#include <sstream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


void text::ecrireFile(string path,char *values) {
	ofstream outfile(path);


	/*for (vector< word_mapping >::const_iterator mit = result.begin();
		mit != result.end();
		mit++)
	{
		outfile << (*mit).first << endl;
	}*/

	outfile.close();



}
