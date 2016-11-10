using System;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Threading.Tasks;
using System.Web.Http;
using System.Web.Http.Description;
using Microsoft.Bot.Connector;
using Newtonsoft.Json;
using System.Runtime.InteropServices;

namespace Grace
{
    [BotAuthentication]
    public class MessagesController : ApiController
    {
        public static bool initSystem = true;

        /*public static RiveScript.RiveScript rs = new RiveScript.RiveScript();

        public static void InitServer()
        {
            rs.setHandler("csharp", new RiveScript.lang.CSharp());
            rs.loadDirectory(AppDomain.CurrentDomain.RelativeSearchPath + "\\RiveFiles");
            rs.sortReplies();
        }*/

        /// <summary>
        /// POST: api/Messages
        /// Receive a message from a user and reply to it
        /// </summary>
        public async Task<HttpResponseMessage> Post([FromBody]Activity activity)
        {
            /*if (initSystem) {
                InitServer();
                initSystem = false;
            }*/
            if (activity.Type == ActivityTypes.Message)
            {
                ConnectorClient connector = new ConnectorClient(new Uri(activity.ServiceUrl));
                // calculate something for us to return
                int length = (activity.Text ?? string.Empty).Length;

                // return our reply to the user
                //Activity reply = activity.CreateReply($"You sent {activity.Text} which was {length} characters");
                string message = WebApiConfig.rs.reply(activity.Conversation.Id,activity.Text);
                Activity reply = activity.CreateReply(message);
                await connector.Conversations.ReplyToActivityAsync(reply);
            }
            else
            {
                Activity reply = HandleSystemMessage(activity);
                ConnectorClient connector = new ConnectorClient(new Uri(activity.ServiceUrl));
                await connector.Conversations.ReplyToActivityAsync(reply);
            }
            var response = Request.CreateResponse(HttpStatusCode.OK);
            return response;
        }

        private Activity HandleSystemMessage(Activity message)
        {
            if (message.Type == ActivityTypes.DeleteUserData)
            {
                // Implement user deletion here
                // If we handle user deletion, return a real message
                return message.CreateReply("Deletando dados do usuário");
            }
            else if (message.Type == ActivityTypes.ConversationUpdate)
            {
                // Handle conversation state changes, like members being added and removed
                // Use Activity.MembersAdded and Activity.MembersRemoved and Activity.Action for info
                // Not available in all channels
                //return message.CreateReply("Olá, sou Grace!");
                return message.CreateReply("Atualizando conversação");
            }
            else if (message.Type == ActivityTypes.ContactRelationUpdate)
            {
                // Handle add/remove from contact lists
                // Activity.From + Activity.Action represent what happened
                return message.CreateReply("Atualizando relação.");
            }
            else if (message.Type == ActivityTypes.Typing)
            {
                // Handle knowing tha the user is typing
                return message.CreateReply("Você está digitando?");
            }
            else if (message.Type == ActivityTypes.Ping)
            {
                return message.CreateReply("Ping!");
            }

            return message.CreateReply("Olá, sou Grace!");
        }
    }
}