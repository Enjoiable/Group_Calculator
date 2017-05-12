//Example 1
	string readme;	
	vector<int> dont;
	vector<int> breifcase;
	cout<<"Please enter a file name:"<<endl;
	cin>>readme;
	ifstream infile(readme);
	int line=0;

	//	if(!infile)// file that does not exist
	//		die();

	while(infile >> line){
		if(count == 0){
			cases = line;
			casenumber = line;
		}
		else{
			breifcase.push_back(line);
		}
		count++;	

	}
////////////////////////////This will read in one "Line at a time" as a string into a vector, 
////////////////////////////not a word a time but the whole line before it sees a return

// example 2

//  upcase fuction provided by the king..
void uppercaseify(string& mystr) {
	for (auto& c : mystr)
		c = toupper(c);
}
int main() {
	Bitfield keys;
	Job_Bitfield jobs;
	Weapon_Bitfield weapons;
	string operation;
	string addon;
	while (cin) {
		cin >> operation; <--- // first cin to grab operation
		uppercaseify(operation);
		if (!cin || cin.eof() || operation == "QUIT") {
			break;
		}
		else 
			if (operation == "ADD") {
				cin >> addon; <--- // each if has a secound cin to grab the next argument
				uppercaseify(addon);
				if (addon[0] == 'J') { 				<--- //grabs the first letter of the string
					jobs= set_job(addon, jobs);
				} else if (addon[0] == 'W') {
					weapons = set_weapon(addon, weapons); <--- // a fuction call based on my class
				} else
					keys = set_key(addon, keys);

			}

			else if (operation == "DELETE") { //using the uppercase fuction previous. 
				cin >> addon;
				uppercaseify(addon);
				if (addon[0] == 'J') {
					jobs = delete_job(addon, jobs);
				} else if (addon[0] == 'W') {
					weapons =delete_weapon(addon, weapons);
				} else
					keys = delete_key(addon, keys);

			} else	if (operation == "QUERY") {
				cin >> addon;
				uppercaseify(addon);
				if (addon[0] == 'J') {
					query_job(addon, jobs);
				} else if (addon[0] == 'W') {
					query_weapon(addon, weapons);
				} else
					query_key(addon, keys);

			}


		//This example will read in a string, then it will read in a secound string based on the first. but if you look im only grabbing the first letter on the string in each if statement. 
