#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<stdint.h>
#include <inttypes.h>
int main(void)
{
    typedef struct {
    unsigned int frame_interface_id;
    int 	     frame_dlt;
    float 	frame_offset_shift;
    float 	frame_time_epoch;
    float 	frame_time_delta;
    float 	frame_time_delta_displayed;
    float 	frame_time_relative;
    unsigned int  	frame_len;
    unsigned int  	frame_cap_len;
    bool 	frame_marked	;
    bool 	frame_ignored	;
    unsigned int 	radiotap_version	;
    unsigned int 	radiotap_pad	;
    unsigned int 	radiotap_length	;//parei
    bool 	radiotap_present_tsft	;
    bool 	radiotap_present_flags	;
    bool 	radiotap_present_rate	;
    bool 	radiotap_present_channel	;
    bool 	radiotap_present_fhss	;
    bool 	radiotap_present_dbm_antsignal	;
    bool 	radiotap_present_dbm_antnoise	;
    bool 	radiotap_present_lock_quality	;
    bool 	radiotap_present_tx_attenuation	;
    bool 	radiotap_present_db_tx_attenuation	;
    bool 	radiotap_present_dbm_tx_power	;
    bool 	radiotap_present_antenna	;
    bool 	radiotap_present_db_antsignal	;
    bool 	radiotap_present_db_antnoise	;
    bool 	radiotap_present_rxflags	;
    bool 	radiotap_present_xchannel	;
    bool 	radiotap_present_mcs	;
    bool 	radiotap_present_ampdu	;
    bool 	radiotap_present_vht	;
    unsigned int	radiotap_present_reserved	;
    bool 	radiotap_present_rtap_ns	;
    bool 	radiotap_present_vendor_ns	;
    bool 	radiotap_present_ext	;
    unsigned int 	radiotap_mactime	;
    bool 	radiotap_flags_cfp	;
    bool 	radiotap_flags_preamble	;
    bool 	radiotap_flags_wep	;
    bool 	radiotap_flags_frag	;
    bool 	radiotap_flags_fcs	;
    bool 	radiotap_flags_datapad	;
    bool 	radiotap_flags_badfcs	;
    bool 	radiotap_flags_shortgi	;
    float 	radiotap_datarate	;
    unsigned int  	radiotap_channel_freq	;
    bool 	radiotap_channel_type_turbo	;
    bool 	radiotap_channel_type_cck	;
    bool 	radiotap_channel_type_ofdm	;
    bool 	radiotap_channel_type_2ghz	;
    bool 	radiotap_channel_type_5ghz	;
    bool 	radiotap_channel_type_passive	;
    bool 	radiotap_channel_type_dynamic	;
    bool 	radiotap_channel_type_gfsk	;
    bool 	radiotap_channel_type_gsm	;
    bool 	radiotap_channel_type_sturbo	;
    bool 	radiotap_channel_type_half	;
    bool 	radiotap_channel_type_quarter	;
    int 	radiotap_dbm_antsignal	;
    unsigned int 	radiotap_antenna	;
    bool 	radiotap_rxflags_badplcp	;
    unsigned int 	wlan_fc_type_subtype	;
    unsigned int 	wlan_fc_version	;
    unsigned int 	wlan_fc_type	;
    unsigned int 	wlan_fc_subtype	;
    unsigned int 	wlan_fc_ds	;
    bool 	wlan_fc_frag	;
    bool 	wlan_fc_retry	;
    bool 	wlan_fc_pwrmgt	;
    bool 	wlan_fc_moredata	;
    bool 	wlan_fc_protected	;
    bool 	wlan_fc_order	;
    unsigned int 	wlan_duration	;
    char 	wlan_ra[17]	;//Receiver address	(Ethernet or other MAC address)
    char	wlan_da[17] 	; //Destination address (Ethernet or other MAC address)
    char 	wlan_ta[17]	; // Transmitter address (Ethernet or other MAC address)
    char 	wlan_sa[17]	;// Source address ((Ethernet or other MAC address))
    char 	wlan_bssid[17]	; //	BSS Id
    unsigned int 	wlan_frag	;
    unsigned int 	wlan_seq	;
    unsigned int 	wlan_bar_type	;
    bool 	wlan_ba_control_ackpolicy	;
    bool 	wlan_ba_control_multitid	;
    bool 	wlan_ba_control_cbitmap	;
    unsigned int  	wlan_bar_compressed_tidinfo	;
    char  	wlan_ba_bm[16]	;
    bool 	wlan_fcs_good	;
    bool 	wlan_mgt_fixed_capabilities_ess	;
    bool 	wlan_mgt_fixed_capabilities_ibss	;
    unsigned int 	wlan_mgt_fixed_capabilities_cfpoll_ap	;
    bool 	wlan_mgt_fixed_capabilities_privacy	;
    bool 	wlan_mgt_fixed_capabilities_preamble	;
    bool 	wlan_mgt_fixed_capabilities_pbcc	;
    bool 	wlan_mgt_fixed_capabilities_agility	;
    bool 	wlan_mgt_fixed_capabilities_spec_man	;
    bool 	wlan_mgt_fixed_capabilities_short_slot_time	;
    bool 	wlan_mgt_fixed_capabilities_apsd	;
    bool 	wlan_mgt_fixed_capabilities_radio_measurement	;
    bool 	wlan_mgt_fixed_capabilities_dsss_ofdm	;
    bool 	wlan_mgt_fixed_capabilities_del_blk_ack	;
    bool 	wlan_mgt_fixed_capabilities_imm_blk_ack	;
    unsigned int  	wlan_mgt_fixed_listen_ival	;
    char 	wlan_mgt_fixed_current_ap[20]	; // Current AP(Ethernet or MAC addres)
    unsigned int 	wlan_mgt_fixed_status_code	;
    unsigned int 	wlan_mgt_fixed_timestamp	;
    unsigned int 	wlan_mgt_fixed_beacon	;
    unsigned int  	wlan_mgt_fixed_aid	;
    unsigned int 	wlan_mgt_fixed_reason_code	;
    unsigned int 	wlan_mgt_fixed_auth_alg	;
    unsigned int 	wlan_mgt_fixed_auth_seq	;
    unsigned int 	wlan_mgt_fixed_category_code	;
    unsigned int 	wlan_mgt_fixed_htact	;
    unsigned int 	wlan_mgt_fixed_chanwidth	;
    unsigned int 	wlan_mgt_fixed_fragment	;
    unsigned int  	wlan_mgt_fixed_sequence	;
    char	wlan_mgt_tagged_all[20] 	;
    char 	wlan_mgt_ssid[30]	;
    unsigned int 	wlan_mgt_ds_current_channel	;
    unsigned int 	wlan_mgt_tim_dtim_count	;
    unsigned int 	wlan_mgt_tim_dtim_period	;
    bool 	wlan_mgt_tim_bmapctl_multicast	;
    unsigned int 	wlan_mgt_tim_bmapctl_offset	;
    unsigned int 	wlan_mgt_country_info_environment	;
    unsigned int  	wlan_mgt_rsn_version	;
    unsigned int 	wlan_mgt_rsn_gcs_type	;
    unsigned int 	wlan_mgt_rsn_pcs_count	;
    unsigned int 	wlan_mgt_rsn_akms_count	;
    unsigned int 	wlan_mgt_rsn_akms_type	;
    bool 	wlan_mgt_rsn_capabilities_preauth	;
    bool 	wlan_mgt_rsn_capabilities_no_pairwise	;
    unsigned int 	wlan_mgt_rsn_capabilities_ptksa_replay_counter	;
    unsigned int 	wlan_mgt_rsn_capabilities_gtksa_replay_counter	;
    bool 	wlan_mgt_rsn_capabilities_mfpr	;
    bool 	wlan_mgt_rsn_capabilities_mfpc	;
    bool 	wlan_mgt_rsn_capabilities_peerkey	;
    int 	wlan_mgt_tcprep_trsmt_pow	;
    int 	wlan_mgt_tcprep_link_mrg	;
    unsigned int 	wlan_wep_iv	;
    unsigned int 	wlan_wep_key	;
    unsigned int 	wlan_wep_icv	;
    char 	wlan_tkip_extiv[20]	;
    char 	wlan_ccmp_extiv[20]	;
    unsigned int 	wlan_qos_tid	;
    unsigned int 	wlan_qos_priority	;
    bool 	wlan_qos_eosp	;
    unsigned int 	wlan_qos_ack	;
    bool 	wlan_qos_amsdupresent	;
    bool 	wlan_qos_buf_state_indicated0	;
    bool 	wlan_qos_bit4	;
    unsigned int 	wlan_qos_txop_dur_req	;
    bool 	wlan_qos_buf_state_indicated1	;
    int 	data_len	;
    char 	classification[7]	;
    }Awid;

    Awid dataset;
    char url[]="teste.txt",nome[20], linha[700];
	FILE *arq;

	arq = fopen(url, "rb");
	if(arq == NULL)
			printf("Erro, nao foi possivel abrir o arquivo\n");
	else{
//		while( (fscanf(arq,"%i,%i,%f,%f,%f\n", &testando.a, &testando.b,&testando.c, &testando.d,&testando.eP))!=EOF )
//			printf("%i teve media %.2f\n", testando.a, testando.d);
            fseek(arq,0,SEEK_SET);
            fgets(linha,1000,arq);
            // 1 - 31
            //32 - 67
            //68 - 103
            //104 - 139
            //140 -  155
            sscanf(linha,"%u,%i,%f,%f,%f,%f,%f,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,\
            %d,%d,%x,%d,%d,%d,%u,%d,%d,%d,%d,%d,%d,%d,%i,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%i,%i,%i,%i,%i,%d\
            ,%x,%d,%d,%d,%d,%d,%d,%u,%s,%s,%s,%s,%s,%d,%i,%i,%d,%d,%d,%i,%s,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%i,%d,%i,%i,%i,\
            %i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%s,%i,%i,%i,%i,%i,%i,%i,%d,%d,%i,%i,%d,%d,%d,%i,%i,%i,%i,%i,%i,%i,\
            %i,%i,%d,%i,%d,%d,%d,%i,%d,%i,%d,%d,%u,%d,%d,%s\n",&dataset.frame_interface_id,&dataset.frame_dlt,&dataset.frame_offset_shift,\
             &dataset.frame_time_epoch,&dataset.frame_time_delta,&dataset.frame_time_delta_displayed,&dataset.frame_time_relative,\
             &dataset.frame_len, &dataset.frame_cap_len,&dataset.frame_marked,&dataset.frame_ignored,&dataset.radiotap_version,\
            &dataset.radiotap_pad,&dataset.radiotap_length,&dataset.radiotap_present_tsft,&dataset.radiotap_present_flags,\
            &dataset.radiotap_present_rate,&dataset.radiotap_present_channel,&dataset.radiotap_present_fhss,\
            &dataset.radiotap_present_dbm_antsignal,&dataset.radiotap_present_dbm_antnoise,&dataset.radiotap_present_lock_quality,\
            &dataset.radiotap_present_tx_attenuation, &dataset.radiotap_present_db_tx_attenuation,\
            &dataset.radiotap_present_dbm_tx_power,&dataset.radiotap_present_antenna,&dataset.radiotap_present_db_antsignal,\
            &dataset.radiotap_present_db_antnoise,&dataset.radiotap_present_rxflags,&dataset.radiotap_present_xchannel,\
            &dataset.radiotap_present_mcs,&dataset.radiotap_present_ampdu, &dataset.radiotap_present_vht,\
            &dataset.radiotap_present_reserved,&dataset.radiotap_present_rtap_ns,&dataset.radiotap_present_vendor_ns,\
            &dataset.radiotap_present_ext,&dataset.radiotap_mactime,&dataset.radiotap_flags_cfp,\
            &dataset.radiotap_flags_preamble,&dataset.radiotap_flags_wep,&dataset.radiotap_flags_frag,\
            &dataset.radiotap_flags_fcs,&dataset.radiotap_flags_datapad,&dataset.radiotap_flags_badfcs,\
            &dataset.radiotap_flags_shortgi,&dataset.radiotap_datarate,&dataset.radiotap_channel_freq,\
            &dataset.radiotap_channel_type_turbo,&dataset.radiotap_channel_type_cck,&dataset.radiotap_channel_type_ofdm,\
            &dataset.radiotap_channel_type_2ghz,&dataset.radiotap_channel_type_5ghz,&dataset.radiotap_channel_type_passive,\
            &dataset.radiotap_channel_type_dynamic,&dataset.radiotap_channel_type_gfsk,\
            &dataset.radiotap_channel_type_gsm,&dataset.radiotap_channel_type_sturbo,&dataset.radiotap_channel_type_half,\
            &dataset.radiotap_channel_type_quarter,&dataset.radiotap_dbm_antsignal,&dataset.radiotap_antenna,\
            &dataset.radiotap_rxflags_badplcp,&dataset.wlan_fc_type_subtype,&dataset.wlan_fc_version,\
            &dataset.wlan_fc_type,&dataset.wlan_fc_subtype,&dataset.wlan_fc_ds,\
            &dataset.wlan_fc_frag,&dataset.wlan_fc_retry,&dataset.wlan_fc_pwrmgt,&dataset.wlan_fc_moredata,\
            &dataset.wlan_fc_protected,&dataset.wlan_fc_order,&dataset.wlan_duration,&dataset.wlan_ra,\
            &dataset.wlan_da,&dataset.wlan_ta,&dataset.wlan_sa,&dataset.wlan_bssid,\
            &dataset.wlan_frag,&dataset.wlan_seq,&dataset.wlan_bar_type,&dataset.wlan_ba_control_ackpolicy,\
            &dataset.wlan_ba_control_multitid,&dataset.wlan_ba_control_cbitmap,&dataset.wlan_bar_compressed_tidinfo,\
            &dataset.wlan_ba_bm, &dataset.wlan_fcs_good,&dataset.wlan_mgt_fixed_capabilities_ess,\
            &dataset.wlan_mgt_fixed_capabilities_ibss,&dataset.wlan_mgt_fixed_capabilities_cfpoll_ap,\
            &dataset.wlan_mgt_fixed_capabilities_privacy,&dataset.wlan_mgt_fixed_capabilities_preamble,\
            &dataset.wlan_mgt_fixed_capabilities_pbcc,&dataset.wlan_mgt_fixed_capabilities_agility,\
            &dataset.wlan_mgt_fixed_capabilities_spec_man,&dataset.wlan_mgt_fixed_capabilities_short_slot_time,\
            &dataset.wlan_mgt_fixed_capabilities_apsd,&dataset.wlan_mgt_fixed_capabilities_radio_measurement,\
            &dataset.wlan_mgt_fixed_capabilities_dsss_ofdm,&dataset.wlan_mgt_fixed_capabilities_del_blk_ack,\
            &dataset.wlan_mgt_fixed_capabilities_imm_blk_ack,&dataset.wlan_mgt_fixed_listen_ival,\
            &dataset.wlan_mgt_fixed_current_ap,&dataset.wlan_mgt_fixed_status_code,&dataset.wlan_mgt_fixed_timestamp,\
            &dataset.wlan_mgt_fixed_beacon,&dataset.wlan_mgt_fixed_aid,&dataset.wlan_mgt_fixed_reason_code,\
            &dataset.wlan_mgt_fixed_auth_alg,&dataset.wlan_mgt_fixed_auth_seq,&dataset.wlan_mgt_fixed_category_code,\
            &dataset.wlan_mgt_fixed_htact,&dataset.wlan_mgt_fixed_chanwidth,&dataset.wlan_mgt_fixed_fragment,\
            &dataset.wlan_mgt_fixed_sequence,&dataset.wlan_mgt_tagged_all,&dataset.wlan_mgt_ssid,\
            &dataset.wlan_mgt_ds_current_channel,&dataset.wlan_mgt_tim_dtim_count,&dataset.wlan_mgt_tim_dtim_period,\
            &dataset.wlan_mgt_tim_bmapctl_multicast,&dataset.wlan_mgt_tim_bmapctl_offset,\
            &dataset.wlan_mgt_country_info_environment,&dataset.wlan_mgt_rsn_version,&dataset.wlan_mgt_rsn_gcs_type,\
            &dataset.wlan_mgt_rsn_pcs_count,&dataset.wlan_mgt_rsn_akms_count,&dataset.wlan_mgt_rsn_akms_type,\
            &dataset.wlan_mgt_rsn_capabilities_preauth,&dataset.wlan_mgt_rsn_capabilities_no_pairwise,\
            &dataset.wlan_mgt_rsn_capabilities_ptksa_replay_counter,&dataset.wlan_mgt_rsn_capabilities_gtksa_replay_counter,\
            &dataset.wlan_mgt_rsn_capabilities_mfpr,&dataset.wlan_mgt_rsn_capabilities_mfpc,\
            &dataset.wlan_mgt_rsn_capabilities_peerkey,&dataset.wlan_mgt_tcprep_trsmt_pow,&dataset.wlan_mgt_tcprep_link_mrg,\
            &dataset.wlan_wep_iv,&dataset.wlan_wep_key,&dataset.wlan_wep_icv,&dataset.wlan_tkip_extiv,&dataset.wlan_ccmp_extiv,\
            &dataset.wlan_qos_tid,&dataset.wlan_qos_priority,&dataset.wlan_qos_eosp,&dataset.wlan_qos_ack,\
            &dataset.wlan_qos_amsdupresent,&dataset.wlan_qos_buf_state_indicated0,&dataset.wlan_qos_bit4,&dataset.wlan_qos_txop_dur_req,\
            &dataset.wlan_qos_buf_state_indicated1,&dataset.data_len,&dataset.classification);


//			printf("%i teve media %.2f\n", testando.a, testando.d);

}
	fclose(arq);
	printf("coisa");
    printf("%s", dataset.wlan_ra);
    return 0;
}
