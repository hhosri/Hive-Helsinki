#ifndef CONTACTCLASS_HPP
#define CONTACTCLASS_HPP

#include <string>

class ContactClass {
    
    private:
        std::string		_firstName;
        std::string		_lastName;
        std::string		_nickname;
		std::string		_darkestSecret;
		std::string		_number;
	
	public:
		ContactClass(void);
		~ContactClass(void);
		
		std::string		getFirstName (void) const;
		std::string		getLastName (void) const;
		std::string		getNickname (void) const;
		std::string		getDarkestSecret (void) const;
		std::string		getNumber (void) const;
        
		void			setFirstName (std::string firstName);
		void			setLastName (std::string lastName);
		void			setNickname (std::string nickname);
		void			setDarkestSecret (std::string darkestSecret);
		void			setNumber (std::string number);
};

#endif