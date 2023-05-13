using UnityEngine;
using UnityEngine.UI;

public class LeaderboardAPI : MonoBehaviour
{
    public string[] playerNames;
    public GameObject playerListUI;
    public GameObject playerSlotPrefab;

    void Start()
    {
        //playerListUI = GameObject.Find("PlayerListUI");
        //playerSlotPrefab = Resources.Load<GameObject>("PlayerSlot");

        DisplayPlayerList();
    }

    void DisplayPlayerList()
    {
        float playerSlotHeight = 17.53632f;

        for (int i = 0; i < playerNames.Length; i++)
        {
            GameObject playerSlot = Instantiate(playerSlotPrefab, playerListUI.transform);
            playerSlot.GetComponent<Image>().color = new Color32(128, 128, 128, 128);
            playerSlot.GetComponentInChildren<Text>().text = playerNames[i];

            RectTransform rectTransform = playerSlot.GetComponent<RectTransform>();
            rectTransform.SetInsetAndSizeFromParentEdge(RectTransform.Edge.Top, 50 + (i * playerSlotHeight), playerSlotHeight);
        }

        playerListUI.GetComponentInChildren<Text>().text = "Player List";
        playerListUI.GetComponent<RectTransform>().sizeDelta = new Vector2(200, 50 + (playerNames.Length * playerSlotHeight));
    }

}
