/*
    A bad use of friend is when it's used to unnecessarily grant access rights to external functions or classes 
    that do not need to intimately interact with the class's internal state, thus breaking encapsulation 
    and potentially leading to tightly coupled code, which is harder to maintain and understand.

    In this bad example, friend is overused, providing unnecessary access to the UserDetails private members. 
    This could be avoided by using public getters or designing the system differently to respect encapsulation. 
    Overuse of friend can make the codebase more difficult to refactor and understand because it creates tight 
    coupling between classes or functions and the classes that declare them as friends.
*/

class UserDetails {
private:
    std::string name;
    int age;

public:
    UserDetails(std::string name, int age) : name(name), age(age) {}

    // Granting friend access to unrelated functions or classes.
    friend void sendEmail(UserDetails& user);
    friend class MarketingCampaign;
};

void sendEmail(UserDetails& user) {
    // This function could have used public getters instead of accessing private members directly.
    std::cout << "Sending email to " << user.name << std::endl;
}

class MarketingCampaign {
    // This class does not need to access UserDetails directly if proper public interfaces were provided.
public:
    void launchCampaign(UserDetails& user) {
        std::cout << "Launching a campaign targeting " << user.age << " year olds." << std::endl;
    }
};
