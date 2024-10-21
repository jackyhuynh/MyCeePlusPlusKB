//
// Created by truc huynh on 10/21/24.
//
#include <iostream>
#include <string>

class UserDetails {
private:
    std::string name;
    int age;

public:
    UserDetails(const std::string& name, int age) : name(name), age(age) {}

    // Public getters to safely expose necessary information.
    const std::string& getName() const { return name; }
    int getAge() const { return age; }
};

void sendEmail(const UserDetails& user) {
    // Now using public getter to access the user’s name.
    std::cout << "Sending email to " << user.getName() << std::endl;
}

class MarketingCampaign {
public:
    void launchCampaign(const UserDetails& user) {
        // Now using public getter to access the user's age.
        std::cout << "Launching a campaign targeting " << user.getAge() << " year olds." << std::endl;
    }
};

int main() {
    UserDetails user("Alice", 30);

    // Use the proper interfaces to interact with UserDetails.
    sendEmail(user);

    MarketingCampaign campaign;
    campaign.launchCampaign(user);

    return 0;
}
