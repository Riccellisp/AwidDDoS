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
%     keyboard;
    %   Filtering responses
    response = dataset(155 +155*[interval]);
    response = response(idx);
    
    %% Filtering Normal
%         idxNormal = find(strcmp(response,'normal') == 1 );
%         sourceNormal = sourceIPs(idxNormal);
%         timeNormal = time(idxNormal);
%         normalType = response(idxNormal);
%         if(isempty (idxNormal))
%             continue;
%         end
%         detection{file} = detectionModule(timeNormal,sourceNormal,...
%             normalType,windowLength,threshold,normalTraffic);
    %% Filtering Attack
%     idxAttack = find(strcmp(response,'normal') ~= 1 );
%     sourceAttack = sourceIPs(idxAttack);
%     timeAttack = time(idxAttack);
%     attackType = response(idxAttack);
%     if(isempty (idxAttack))
%         continue;
%     end
%     detection{file} = detectionModule(timeAttack,sourceAttack,...
%         attackType,windowLength,threshold,normalTraffic);
    
    
    
    %% By destination approach
        uniqueDestinations =  unique(destinationIPs);
    
        for k = 1:length(uniqueDestinations)
            %% Filtering by destination
            idxDestination = find(strcmp(destinationIPs, uniqueDestinations(k)));
            sourceByDestination = (sourceIPs(idxDestination));
            timeByDestination = time(idxDestination);
            responseByDestination = response(idxDestination);
    
            %% Filtering attacks
%             idxAttack = find(strcmp(responseByDestination,'normal') ~= 1 );
%             sourceAttack = sourceByDestination(idxAttack);
%             timeAttack = timeByDestination(idxAttack);
%             attackType = responseByDestination(idxAttack);
%             if(isempty (idxAttack))
%                 continue;
%             end
    
            %% Filtering only flooding Attacks
            idxAttack = find(strcmp(responseByDestination,'impersonation') == 1 );
            sourceAttack = sourceByDestination(idxAttack);
            timeAttack = timeByDestination(idxAttack);
            attackType = responseByDestination(idxAttack);
            if(isempty (idxAttack))
                continue;
            end
    
            %% Filtering Normal
%             idxNormal = find(strcmp(responseByDestination,'normal') == 1 );
%             sourceNormal = sourceByDestination(idxNormal);
%             timeNormal = timeByDestination(idxNormal);
%             normalType = responseByDestination(idxNormal);
%             if(isempty (idxNormal))
%                 continue;
%             end
    
            %% Calling detection Module
            %         numeroAtaques, numeroNormal,falsePositive,falseNegative,...
            %         accuracy,packetRate, varSourceIPs, entropySourceIPs,realWindowResponse
            %% Mixed packets
            %         detection{file,k} = detectionModule(timeByDestination,sourceByDestination,...
            %             responseByDestination,windowLength,threshold,normalTraffic);
            %%  Only Attack packets
            detection{file,k} = detectionModule(timeAttack,sourceAttack,...
                attackType,windowLength,threshold,normalTraffic);
            %% Only Normal packets
%             detection{file,k} = detectionModule(timeNormal,sourceNormal,...
%                 normalType,windowLength,threshold,normalTraffic);
        end
    
    
    cd AWID-CLS-R-Tst
end
save('AWID-CLS-R-TstonlyNormalByDest.mat','detection');
