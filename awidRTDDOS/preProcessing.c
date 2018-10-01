#include "defs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>

static int
cmpstringp(const void *p1, const void *p2)
{
   /* The actual arguments to this function are "pointers to
      pointers to char", but strcmp(3) arguments are "pointers
      to char", hence the following cast plus dereference */

   return strcmp(* (char * const *) p1, * (char * const *) p2);
}

int cstring_cmp(const void *a, const void *b)
{
    const char **ia = (const char **)a;
    const char **ib = (const char **)b;
    return strcmp(*ia, *ib);
	/* strcmp functions works exactly as expected from
	comparison function */
}

void print_cstring_array(char **array, size_t len)
{
    size_t i;

    for(i=0; i<len; i++)
        printf("%s | ", array[i]);

    putchar('\n');
}

float sourceIPsEntropy(char *sourceIPs,int len){
//    size_t len = strlen(sourceIPs);
    int i,j;
    float result = 0.0;

    float total=0.0;
    printf("entrei na entropia\n");
    printf("valor de len %d\n", len);

    // ordena a lista de IPs
    qsort(sourceIPs, len  , sizeof(char *) , strcmp);
    printf("chamando prob1\n");
    // calcula a probabilidade do primeiro ip da lista ordenada
    result=prob1(sourceIPs, sourceIPs,len);
    printf("valor de result %lf\n",result);

    printf("prob de %s é %f\n",sourceIPs,result);
    // acumula ...e no final o acumulado tem q dar 1
    total+=result;

    // varre o restante da lista ordenada, por isso i comeca em 1
    for (i=1;i<(len-1);i++) {

      // calcula e acumula a probabilidade do elemento i, caso já não tenha sido calculada, por isso comparação
      if (strcmp(sourceIPs+18*(i-1),sourceIPs+18*i)) {
		result=prob1(sourceIPs+18*i, sourceIPs+18*i,len);
		total+=result*(log10(result)/log10(2));
      		//printf("prob de %s é %f\n",sourceIPs+18*i,result);
      }

    }
    printf("valor do log %f\n", log10(10));

    printf("valor de result %f\n",result);
    return  - total;

    /*for (i=0;i<(len-1);i++){
       printf("sourceIPs=%s\n", sourceIPs+18*i);
    }
    for (i=0;i<len;i++){
        for (j=0;j<18;j++){

        result = result +
        prob1(sourceIPs,
        *(sourceIPs + 18*i + j),&len) + log2(prob1(sourceIPs,
        *(sourceIPs + 18*i + j),&len)

);
        }
    }*/

    //return result;
}

void preProcessing (){
int i,aux,t,j;
aux = 0;
t = 0;
//Awid dataset[600];
Awid *dataset;
char url[]="teste.txt",nome[20], linha[700];
FILE *arq;

double *frame_time_epoch;
double first_packet_window;
//char sourceIPs[600][18];
char *sourceIPs;

char *destinationIPs;

float  entropy,sourceIPsVar;
int packetRate;




char    *typeOfFile(mode_t);
char    *permOfFile(mode_t);
void     outputStatInfo(char *, struct stat *);

    char *filename;
    struct stat st;


        if (lstat("1", &st) < 0) {
            perror("1");
            putchar('\n');
            return 0;
        }

        printf("o tamanho do arquivo eh %d\n",st.st_size);


	arq = fopen(url, "rb");

 	dataset=malloc(sizeof(Awid));

        if(dataset==NULL) {
      		printf("nao pode alocar\n");
		return 0;
	}
        printf("%d",sizeof(Awid));
        fflush(stdout);

	if(arq == NULL)
			printf("Erro, nao foi possivel abrir o arquivo\n");
	else{
//		while( (fscanf(arq,"%[^,],%[^,],%[^,],%[^,],%[^,]\n", &testando.a, &testando.b,&testando.c, &testando.d,&testando.eP))!=EOF )
//			prcharf("%[^,] teve media %.2f\n", testando.a, testando.d);

            fseek(arq,0,SEEK_SET);
//	    while(!feof(arq) || i < 100000) {
        for(i = 0;!feof(arq); i++ ){
            dataset=realloc(dataset, (i+2)*sizeof(Awid));
            fgets(linha,2000,arq);
            sscanf(linha,"%u,%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],\
            %[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%x,%[^,],%[^,],%[^,],%[^,],\
            %[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],\
            %[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],\
            %[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],\
            %[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],\
            %[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],\
            %[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,]\n",\
            &dataset[i].frame_interface_id,&dataset[i].frame_dlt,&dataset[i].frame_offset_shift,\
            &dataset[i].frame_time_epoch,&dataset[i].frame_time_delta,&dataset[i].frame_time_delta_displayed,&dataset[i].frame_time_relative,\
            &dataset[i].frame_len, &dataset[i].frame_cap_len,&dataset[i].frame_marked,&dataset[i].frame_ignored,&dataset[i].radiotap_version,\
            &dataset[i].radiotap_pad,&dataset[i].radiotap_length,&dataset[i].radiotap_present_tsft,&dataset[i].radiotap_present_flags,\
            &dataset[i].radiotap_present_rate,&dataset[i].radiotap_present_channel,&dataset[i].radiotap_present_fhss,\
            &dataset[i].radiotap_present_dbm_antsignal,&dataset[i].radiotap_present_dbm_antnoise,&dataset[i].radiotap_present_lock_quality,\
            &dataset[i].radiotap_present_tx_attenuation, &dataset[i].radiotap_present_db_tx_attenuation,\
            &dataset[i].radiotap_present_dbm_tx_power,&dataset[i].radiotap_present_antenna,&dataset[i].radiotap_present_db_antsignal,\
            &dataset[i].radiotap_present_db_antnoise,&dataset[i].radiotap_present_rxflags,&dataset[i].radiotap_present_xchannel,\
            &dataset[i].radiotap_present_mcs,&dataset[i].radiotap_present_ampdu, &dataset[i].radiotap_present_vht,\
            &dataset[i].radiotap_present_reserved,&dataset[i].radiotap_present_rtap_ns,&dataset[i].radiotap_present_vendor_ns,\
            &dataset[i].radiotap_present_ext,&dataset[i].radiotap_mactime,&dataset[i].radiotap_flags_cfp,\
            &dataset[i].radiotap_flags_preamble,&dataset[i].radiotap_flags_wep,&dataset[i].radiotap_flags_frag,\
            &dataset[i].radiotap_flags_fcs,&dataset[i].radiotap_flags_datapad,&dataset[i].radiotap_flags_badfcs,\
            &dataset[i].radiotap_flags_shortgi,&dataset[i].radiotap_datarate,&dataset[i].radiotap_channel_freq,\
            &dataset[i].radiotap_channel_type_turbo,&dataset[i].radiotap_channel_type_cck,&dataset[i].radiotap_channel_type_ofdm,\
            &dataset[i].radiotap_channel_type_2ghz,&dataset[i].radiotap_channel_type_5ghz,&dataset[i].radiotap_channel_type_passive,\
            &dataset[i].radiotap_channel_type_dynamic,&dataset[i].radiotap_channel_type_gfsk,\
            &dataset[i].radiotap_channel_type_gsm,&dataset[i].radiotap_channel_type_sturbo,&dataset[i].radiotap_channel_type_half,\
            &dataset[i].radiotap_channel_type_quarter,&dataset[i].radiotap_dbm_antsignal,&dataset[i].radiotap_antenna,\
            &dataset[i].radiotap_rxflags_badplcp,&dataset[i].wlan_fc_type_subtype,&dataset[i].wlan_fc_version,\
            &dataset[i].wlan_fc_type,&dataset[i].wlan_fc_subtype,&dataset[i].wlan_fc_ds,\
            &dataset[i].wlan_fc_frag,&dataset[i].wlan_fc_retry,&dataset[i].wlan_fc_pwrmgt,&dataset[i].wlan_fc_moredata,\
            &dataset[i].wlan_fc_protected,&dataset[i].wlan_fc_order,&dataset[i].wlan_duration,dataset[i].wlan_ra,\
            dataset[i].wlan_da,dataset[i].wlan_ta,dataset[i].wlan_sa,dataset[i].wlan_bssid,\
            &dataset[i].wlan_frag,&dataset[i].wlan_seq,&dataset[i].wlan_bar_type,&dataset[i].wlan_ba_control_ackpolicy,\
            &dataset[i].wlan_ba_control_multitid,&dataset[i].wlan_ba_control_cbitmap,&dataset[i].wlan_bar_compressed_tidinfo,\
            &dataset[i].wlan_ba_bm, &dataset[i].wlan_fcs_good,&dataset[i].wlan_mgt_fixed_capabilities_ess,\
            &dataset[i].wlan_mgt_fixed_capabilities_ibss,&dataset[i].wlan_mgt_fixed_capabilities_cfpoll_ap,\
            &dataset[i].wlan_mgt_fixed_capabilities_privacy,&dataset[i].wlan_mgt_fixed_capabilities_preamble,\
            &dataset[i].wlan_mgt_fixed_capabilities_pbcc,&dataset[i].wlan_mgt_fixed_capabilities_agility,\
            &dataset[i].wlan_mgt_fixed_capabilities_spec_man,&dataset[i].wlan_mgt_fixed_capabilities_short_slot_time,\
            &dataset[i].wlan_mgt_fixed_capabilities_apsd,&dataset[i].wlan_mgt_fixed_capabilities_radio_measurement,\
            &dataset[i].wlan_mgt_fixed_capabilities_dsss_ofdm,&dataset[i].wlan_mgt_fixed_capabilities_del_blk_ack,\
            &dataset[i].wlan_mgt_fixed_capabilities_imm_blk_ack,&dataset[i].wlan_mgt_fixed_listen_ival,\
            &dataset[i].wlan_mgt_fixed_current_ap,&dataset[i].wlan_mgt_fixed_status_code,&dataset[i].wlan_mgt_fixed_timestamp,\
            &dataset[i].wlan_mgt_fixed_beacon,&dataset[i].wlan_mgt_fixed_aid,&dataset[i].wlan_mgt_fixed_reason_code,\
            &dataset[i].wlan_mgt_fixed_auth_alg,&dataset[i].wlan_mgt_fixed_auth_seq,&dataset[i].wlan_mgt_fixed_category_code,\
            &dataset[i].wlan_mgt_fixed_htact,&dataset[i].wlan_mgt_fixed_chanwidth,&dataset[i].wlan_mgt_fixed_fragment,\
            &dataset[i].wlan_mgt_fixed_sequence,&dataset[i].wlan_mgt_tagged_all,&dataset[i].wlan_mgt_ssid,\
            &dataset[i].wlan_mgt_ds_current_channel,&dataset[i].wlan_mgt_tim_dtim_count,&dataset[i].wlan_mgt_tim_dtim_period,\
            &dataset[i].wlan_mgt_tim_bmapctl_multicast,&dataset[i].wlan_mgt_tim_bmapctl_offset,\
            &dataset[i].wlan_mgt_country_info_environment,&dataset[i].wlan_mgt_rsn_version,&dataset[i].wlan_mgt_rsn_gcs_type,\
            &dataset[i].wlan_mgt_rsn_pcs_count,&dataset[i].wlan_mgt_rsn_akms_count,&dataset[i].wlan_mgt_rsn_akms_type,\
            &dataset[i].wlan_mgt_rsn_capabilities_preauth,&dataset[i].wlan_mgt_rsn_capabilities_no_pairwise,\
            &dataset[i].wlan_mgt_rsn_capabilities_ptksa_replay_counter,&dataset[i].wlan_mgt_rsn_capabilities_gtksa_replay_counter,\
            dataset[i].wlan_mgt_rsn_capabilities_mfpr,&dataset[i].wlan_mgt_rsn_capabilities_mfpc,\
            &dataset[i].wlan_mgt_rsn_capabilities_peerkey,&dataset[i].wlan_mgt_tcprep_trsmt_pow,&dataset[i].wlan_mgt_tcprep_link_mrg,\
            &dataset[i].wlan_wep_iv,&dataset[i].wlan_wep_key,&dataset[i].wlan_wep_icv,&dataset[i].wlan_tkip_extiv,&dataset[i].wlan_ccmp_extiv,\
            &dataset[i].wlan_qos_tid,&dataset[i].wlan_qos_priority,&dataset[i].wlan_qos_eosp,&dataset[i].wlan_qos_ack,\
            &dataset[i].wlan_qos_amsdupresent,&dataset[i].wlan_qos_buf_state_indicated0,&dataset[i].a,\
            &dataset[i].wlan_qos_txop_dur_req,&dataset[i].wlan_qos_buf_state_indicated1,\
            &dataset[i].data_len,&dataset[i].classification);
//            i = i++;

//            while (!isWindow(atof(dataset[aux2].frame_time_epoch),frame_time_epoch[aux],1.0)){
//                printf("coisa\n");
//
//            }
                    printf(" o pacote %d possui o tempo %s e o ip %s\n",i,dataset[i].frame_time_epoch, dataset[i].wlan_sa);

            } // guardei o dataset em uma variável
            fclose(arq);


            printf("o valor acumulado de i %d",i);

            sourceIPs = malloc(18*sizeof(char));
            frame_time_epoch = malloc(sizeof(double));

            for(j = 0; j<= i; j++){
                if((strcmp(dataset[j].frame_time_epoch,"?") != 0) && (strcmp(dataset[j].wlan_da,"?")!= 0) && (strcmp(dataset[j].wlan_ra,"?")!= 0) ){


                    frame_time_epoch=realloc(frame_time_epoch, (aux+1)*sizeof(double));
                    //destinationIPs= realloc(destinationIPs, 18*(aux+1)*sizeof(char) + 18);
                    //printf("tamanho de %d\n", 18*(aux+1)*sizeof(char));
                                        printf("começando a acumular\n");

                	frame_time_epoch[aux] = atof(dataset[j].frame_time_epoch);

                    //printf("%lf\n", frame_time_epoch[0]);
//                printf("%d\n",isWindow(frame_time_epoch[0],frame_time_epoch[aux],1.0));
                    printf("sera que eh janela\n");
                    printf("valor de aux %d\n",aux);
                    printf("o tempo é %lf\n",frame_time_epoch[aux]);

                    printf("tempo t %d e o tempo aux é %d\n", t,aux);

                if (!isWindow(frame_time_epoch[t],frame_time_epoch[aux],1.0)){
                    printf("realloc\n");
                    sourceIPs= realloc(sourceIPs, 18*(aux+1)*sizeof(char));
                    printf("vou copiar %s em sourceIPs\n",dataset[j].wlan_sa);
                    strcpy((sourceIPs+18*(aux)) , dataset[j].wlan_sa);
                    printf("copiei\n");
                    printf("ip copiado %s\n", sourceIPs);
                    aux++;
//                    treta++;
//                    printf("coisa,%d\n",treta);
                      printf("acumulando %s\n",dataset[j].wlan_sa);

                }
                else{
                    t = t +j;

                    printf("formou janela e aux:%d\n",aux);

                    printf("ip %s\n", sourceIPs );
//                    break;
                    entropy = sourceIPsEntropy(sourceIPs,aux);
                    printf("valor de entropia %f\n",entropy);
                    break;
                }

            	}
            	else{
//            	printf("presta n, %d\n", treta);
                continue;

            	}







            }


                //destinationIPs = malloc(18*sizeof(char));
                //destinationIPs = malloc(18*sizeof(char));

                //printf("%d\n", aux);
               //entropy = sourceIPsEntropy(sourceIPs,20);




    //entropy = sourceIPsEntropy(sourceIPs,aux + 1);
    //printf("%f\n",Log2(2));

    }
}
