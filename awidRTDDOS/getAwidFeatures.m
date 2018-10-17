% % parameters
windowLength = 1;
threshold = 0.8;
normalTraffic = [539, 0.005000000000000, 1.319659453970128   ];

cd testesplit
files = dir('new*');

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
    keyboard;
    
    firstPacketWindowTime = time(1) + 1;
    n = 0;
    nextPkt = 1;
    janelas = 0;
    numeroAtaques = 0;
    numeroNormal = 0;
    flagAttack = 0;
    flagNormal = 0;
    falsePositive = 0;
    falseNegative = 0;
    errors = 0;
    
%     todo
    for k = 1:length(unique(destinationIPs))
    idxDestination = find(strcmp(destinationIPs, destinationIPs(k)));
    end
    
    while(nextPkt < length(idx))
%       Splitting in seconds        
        for i = nextPkt:length(idx)
            if(~isWindow(time(nextPkt),time(i),windowLength))
                n = n + 1;
            else
                break;
            end
        end
%       Geting true responses        
        if (~isempty(find(strcmp(response(nextPkt:n),'normal') ~= 1 )))
            disp('tem ataque real');
            flagAttack = 1;
        else
            flagNormal = 1;
        end
        
%         Getting Features
        
        entropySourceIPs= entropy2([sourceIPs(nextPkt:n)]);
        varSourceIPs = length(unique([sourceIPs(nextPkt:n)]))/length(sourceIPs);
        packetRate = n;
%         Detection Module
        NaHidModule = NaHid([packetRate varSourceIPs entropySourceIPs],normalTraffic);
        janelas = janelas + 1;
        nextPkt = n + 1;
        
        if(NaHidModule <  threshold)
            disp('traffic');
            disp(janelas);
            disp('atack');
            numeroAtaques = numeroAtaques + 1;
            
%                 Getting false negatives and errors
            
            if(flagNormal)
                falsePositive= falsePositive + 1;
                errors = errors + 1;
            end
%             plotResultsAwid(NaHidModule,threshold,entropySourceIPs,varSourceIPs,packetRate);

            
        else
            disp('traffic');
            disp(janelas);
            disp('normal');
            
            normalTraffic = [packetRate varSourceIPs entropySourceIPs];
            numeroNormal = numeroNormal+ 1;
            
            if(flagAttack)
%                 Getting false negatives and errors
                falseNegative = falseNegative + 1;
                errors = errors + 1;
            end
%             plotResultsAwid(NaHidModule,threshold,entropySourceIPs,varSourceIPs,packetRate);

        end
        
%       Getting detection rate        
        accuracy = (1 - errors/janelas);
        
    end
    cd testesplit
end