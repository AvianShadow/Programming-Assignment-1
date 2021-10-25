//Jacob Pinksa JRP180005
#include <iostream>
#include <string>
#include <sstream>
#include "version.cpp"
// This is a comment hi 

using namespace std;
static string version = "1.2";
int main()
{
	displayVersion(version);
	string url;

	string temp = "";

	int periods = 0;

	string protocol = "";
	string domain = "";
	string port = "";
	string filePath = "";
	string param = "";

	bool errorPro = false;
	bool errorDom = false;
	bool errorPor = false;
	bool errorFil = false;
	bool errorPar = false;

	cin >> url;

	for(int i = 0; i < url.size(); i++)
	{
		if(url.at(i) == ':' && url.at(i+1) == '/' && url.at(i+2) == '/')
		{
			protocol = temp;
				if(temp.compare("http") != 0 && temp.compare("https") != 0 && temp.compare("ftp") != 0 && temp.compare("ftps"))
				{
					errorPro = true;
					temp = "";
					i += 2;
				}
				else
				{
					protocol = temp;
					temp = "";
					i += 2;
				}
	}
	else if(url.at(i) == ':')
	{
	domain = temp;
	temp = ":";
	}
	else if(url.at(i) == '/')
	{
		if(temp.at(0) == ':')
		{
			port = temp;
			temp = "/";
		}
		else if(temp.at(0) == '/')
		{
			temp += url.at(i);
		}
		else
		{
			domain = temp;
			temp = "/";
		}
	}
	else if(url.at(i) == '?')
	{
		filePath = temp;
		temp = "?";
	}
	else if(i == (url.size()-1))
	{
		if(temp.at(0) == '/')
		{
			filePath = temp;
			temp = "";
		}
		else if(temp.at(0) == '?')
		{
			param = temp;
			temp = "";
		}
		else if(filePath == "")
			cout << "Error, incorrect formatting\n";
	}

	else
		temp += url.at(i);

	}

	for(int i = 0; i < domain.size(); i++)
		{
			if(domain.at(i) == '.')
				periods++;
		}
	if(periods != 2)
		errorDom = true;

	if(domain.substr(domain.find_last_of(".") + 1).compare("com") == 0 || domain.substr(domain.find_last_of(".") + 1).compare("net") == 0 || domain.substr(domain.find_last_of(".") + 1).compare("edu") == 0 || domain.substr(domain.find_last_of(".") + 1).compare("biz") == 0 || domain.substr(domain.find_last_of(".") + 1).compare("gov") == 0)
		errorDom = false;
		else
		errorDom = true;
	if(port != "")
		{
		stringstream s1(port.substr(1));
		int n1;
		s1 >>n1;

		if(n1 > 0 && n1 < 65536)
		{
			errorPor = false;
		}
		else
			errorPor = true;
		}
	if(filePath != "")
	{
		if(filePath.substr(filePath.find_last_of(".")).compare(".html") != 0 && filePath.substr(filePath.find_last_of(".")).compare(".htm") != 0)
		{
			errorFil = true;
		}
	}

	if(param != "")
	{
		if(param.find("=") == -1)
		{
			errorPar = true;
		}
	}

	if(errorPro == false && errorDom == false && errorPor == false && errorFil == false && errorPar == false)
	{

		cout << "Protocol: " << protocol << "\n";
		cout << "Domain: " << domain << "\n";
		cout << "Port: " << port.substr(1) << "\n";
		cout << "File Path: " << filePath << "\n";
		cout << "Parameter: " << param.substr(1) << "\n";
	}
	if(errorPro == true || errorDom == true || errorPor == true || errorFil == true || errorPar == true)
		cout << "Invalid URL with Incorrect Components\n";

	if(errorPro == true)
		cout << "Error: Protocol = " << protocol << " is not a valid protocol.\n";
	if(errorDom == true)
		cout << "Error: Domain = " << domain << " is an invalid domain name.\n";
	if(errorPor == true)
		cout << "Error: Port = " << port << " port number must be between 1 and 65535.\n";
	if(errorFil == true)
	{
		cout << "Error: File Path = " << filePath.substr(filePath.find_last_of(".") + 1) << " is an invalid file path.\n";
	}
	if(errorPar == true)
	{
		cout << "Error: Parameter = " << param.substr(1) << " does not contain an assignment operator.";
	}


}
