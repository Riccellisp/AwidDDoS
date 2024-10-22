% % parameters
windowLength = 1;
threshold = 0.8;
normalTraffic = [539, 0.005000000000000, 1.319659453970128   ];

cd AWID-CLS-R-Tst
files = dir('mixed*');

for file=1:length(files)    
    dataset = textread(files(file).name, '%s', 'delimiter', ',','whitespace', '');
    cd ..
    interval = 0:((length(dataset)/155)-1);
    sourceIPs = dataset(79 +155*[interval]);
    destinationIPs = dataset(77 +155*[interval]);
    %  Removing invalid IPs
    sourceIPs = sourceIPs(~strcmp(destinationIPs,'?'));
    destinationIPs = destinationIPs(~strcmp(destinationIPs,'?'));
    
    idx = find(~strcmp(destinationIPs,'?'));    
    %  Filtering time
    time = str2double(dataset(4 +155*[interval]));
    time = time(idx);
    %   Filtering responses
    response = dataset(155 +155*[interval]);
    response = response(idx);

    uniqueDestinations =  unique(destinationIPs);
    
    for k = 1:length(uniqueDestinations)
%% Filtering by destination         
        idxDestination = find(strcmp(destinationIPs, uniqueDestinations(k)));       
        sourceByDestination = (sourceIPs(idxDestination));
        timeByDestination = time(idxDestination);
        responseByDestination = response(idxDestination);
%% Calling detection Module
%         numeroAtaques, numeroNormal,falsePositive,falseNegative,...
%         accuracy,packetRate, varSourceIPs, entropySourceIPs,realWindowResponse
        detection{file,k} = detectionModule(timeByDestination,sourceByDestination,...
            responseByDestination,windowLength,threshold,normalTraffic);
    end
    cd AWID-CLS-R-Tst
end
    save('detection3.mat','detection');
