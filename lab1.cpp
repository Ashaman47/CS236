#include <cctype>
#include "Token.h"
#include "Scanner.h"
#include <vector>
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

using namespace std;

int main(int argc, char* argv[]) {
	string filename = argv[1];
	Scanner scanner(filename);

	return 0;
}
