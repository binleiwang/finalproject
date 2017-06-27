bool isEmployee(string input)
{
	string password;
	int i = 3;
	if (input == "E" || input == "e")
	{
		cout << "Please key in the password: ";
		getline(cin, password);
		while(password != "you suck")
		{
			i--;
			if(i == 0)
			{
				cout <<  "System warning: You suck!" << endl;
				return false;
			}
			cout << "Wrong password, you have " << i << " more chances" << endl;
			cout << "Please key in the password: ";
			getline(cin, password);
		}
		return true;
	}
	return false;
}



void NMT::printMiniMenuFormatted(ostream &out)
{
	cout << "________________________________________________________Shortlist of Robots"
			"________________________________________________________\n";
	cout << "______________________________________________Name_________________"
			"______________________________________ASIN______________________\n";
	printMiniMenu(out);
	cout << "_________________________________________________________________\n";
}
