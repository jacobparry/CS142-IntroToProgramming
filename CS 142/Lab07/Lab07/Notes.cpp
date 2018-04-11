/////////////
/*
//show top contestants
ask judge his top 5, one at a time
shuffle contestants before showing remaining choices
reprompt after bad imput
once a contestant is chosen, removed from remaining contestants
once finished, must show his top 5

const int NOTFOUND = -1;

void populate (vector<stings>& people)
{
people.push_back("sally");

}


void show_contestants(vector<stings> people)
{
for (int i = 0; i < people.size(); i++)
{
cout people[i] << endl;
}
}

int find_contestants(vector<stings> people, toFind)
{
for (size_t i = 0; i < people.size(); i++)
{
if (people[i] == toFind)
{
return i;
}
}
return NOTFOUND;

}

void shuffle(vector<stings>& people)
{
const int times_to_shuffle = 100;

for (int i = 0; i < times_to_shuffle; i++)
{
int random1 = rand() % people.size();
int random2 = rand() % people.size();

if (random1 != random2)
{
string contest1 = people[random1];
string contest2 = people[ramdon2];

people[random1] = constest2;
people[random2] = contest1;
}

}

}

vector<string> choose_top (vector<stings> people)
{
//step 1:shuffle remaining
//step 2: show
//step 3: find
step 3b: if not found, ask again, invalid
//step 4: add to top 5 vector;

vector<string> topFive;


for (int i = 0; i < 5; i++)
{
shuffle(people);
show();
cout << what do you want?;
string pick;

cin.sync();
getline(cin, pick)

int location = find(people, pick)

topFive.push_back(people[location]);
people.erase(people.begin() + location);  //////////////////use this to shuffle with 2 different vectors. makes it easier.
}
return topFIve;
}

vector<string> contestants;





bool flag = true;
vector<string> winner;
vector<string> temp;
int position1 = 0;
int position2 = 1;

int max_rounds = total_round(restaurants);
int current_round = 0;

while (flag)
{
bool power = power_of_two(restaurants);
if (power != false)
{
for (int round = 0; round < max_rounds; round++)
{
int number_of_restaurants = 0;
for (int i = 0; i < restaurants.size(); i++)
{
number_of_restaurants++;
}
int matches = number_of_restaurants / POW_OF_2;

current_round++;
for (int match = 1; match <= matches; match++)
{
string restaurant_choice;
cout << "Please choose one of the following two options.\n\n";
cout << "Match " << match << "/" << matches << ", Round " << current_round << "/" << max_rounds << " ";
cout << restaurants[position1] << " or " << restaurants[position2] << ": ";

cin.sync();
getline(cin, restaurant_choice);

temp.push_back(restaurant_choice);
restaurants.erase(restaurants.begin() + position1);
restaurants.erase(restaurants.begin() + position1);

}
restaurants = temp;
temp = winner;
}
}
else
{
cout << "Please make # of restaurants a power of 2 ";
flag = false;
}
}


*/