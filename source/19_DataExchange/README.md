# Data Exchange

## Structure
```css
./source/19_DataExchange/
    ├── data-service/
    │   ├── main.cpp
    │   └── Dockerfile
    ├── client-service/
    │   ├── main.cpp
    │   └── Dockerfile
    └── docker-compose.yml
```

## Run the App:
- Navigate to the 19_DataExchange folder
```bash
# Assume I am inside the CPLUS_SAMPLE_CODE directory
cd source/19_DataExchange
```
- Run the app
```bash
# Build the images and run the containers
docker-compose up --build
```
